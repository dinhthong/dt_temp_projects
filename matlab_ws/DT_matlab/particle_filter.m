function MCLin1Dsimple
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SIGmeas = 1;  %standard deviation of measurement noise
SIGproc = 0.5; %standard deviation of process noise
SIGinit = 4; %standard deviation of initial position

M = 100;  %number of particles (the more, the better the particle
%Probability Mass Function (PMF) matches the true Probability Distribution
% Function (PDF).
CHI = [SIGinit*randn(M,1), ones(M,1)/M];  %array of particles and associated weights, v? tr? và tr?ng s? c?a v? trí ?ó
xACTt = SIGinit*randn(1); %true position of the robot (unknown to particles)
ut = 5; % control input (constant motion in x-directi on)
max_moves = 10; 
for mv = 1:max_moves
    str1=strcat('Move ',int2str(mv));
    disp(str1);
    % move ACTUAL robot. yo it can be anything, like we simulate something
    % moving that's all
    xACTt = sample_motion_model(ut, xACTt, SIGproc)
    %take measurement - signal feedbacked from sensors. list all possible
    %next position it can be, to calculate step 5. 90/492
    zt = take_measurement(xACTt,SIGmeas);
    % apply particle filter
    CHI_prev = CHI; %saving the old partcles (optional)
    [CHI,CHIbar] = AlgorithmMCL( CHI, ut, zt, SIGproc, SIGmeas);
    xMEA=sum(CHI(:,1).*CHI(:,2))
    error=xACTt-xMEA
end
end

function [CHIt,CHIbart] =  AlgorithmMCL( CHItm1, ut,zt,SIGproc,SIGmeas)
%Implements Monte Carlo Localization (MCL) algorithm, Table 8.2, page 252,
%"Probabilistic Robotics"
M = size(CHItm1,1);
CHIbart = zeros(size(CHItm1));
CHIt = zeros(size(CHItm1));
N = 0; %normalization factor
for m = 1:M
    xtm1 = CHItm1(m,1);
    %step 4
    xt = sample_motion_model(ut, xtm1,SIGproc); % ung voi moi particle ? x_t-1, ta ss tính duocc xt
    %step 5
    wt = measurement_model(zt, xt, SIGmeas);
    %step 6
    CHIbart(m,:) = [xt,wt]; % xt along with probability wt
    N = N+wt; % N is used for next line of code
end

% normalize
cumwt = cumsum(CHIbart(:,2))/N;
% resample, to convert from a mess to standard particle for next loop
for m = 1:M %Resampling step 8 ....
    %draw m-th sample with probability proportional to wt with two methods:
    swt = rand; %1.) randomly sample-> uniform distribution
    %swt = cumwt(end)/M*(m-1/2); %2.) swt steps through CMF, and selects
    %the associated particle.  This is a low-variance sampling method.
    index = find( cumwt>= swt, 1, 'first'); % I = find(X,K,'first') is the same as I = find(X,K).
    xt = CHIbart(index,1); %select xt randomly from CHIbart
    %step10
    CHIt(m,:) = [xt,1/M]; %add particle to CHI
end
end
%input: tin hieu dieu khien, gia tri truoc do, + noise do khi ta tác dong
%ví du dien ap de dieu khien toc do thì luôn có nhieu!
%ok
function xt = sample_motion_model(ut, xtm1, SIGproc)
%sample with 1D noise
xt = xtm1 + ut+ SIGproc*randn(1);
end
%{
input:
%}
function wt = measurement_model(zt, xt, SIGmeas)
% evaluate likelihood of measurement zt given prior with mean xt and std SIGmeas
wt = 1/(2*pi*SIGmeas^2)^(1/2)*exp(-1/2*(xt-zt)^2/SIGmeas^2); %% công th?c xs ?ã h?c trong xstk
end
%ok
% input: actual position 
% output: zt = actual position + noise
function zt = take_measurement(xACTt,SIGmeas)
% actual state pertubed by Gaussian noise
zt = xACTt+randn(1)*SIGmeas;
end
