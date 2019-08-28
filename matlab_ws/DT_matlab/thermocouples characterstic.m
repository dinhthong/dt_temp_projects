% Do luong cong nghiep
% Read from excel file
data=xlsread('C:\Users\nguye\Downloads\thermocouple-equations-from-nist-data.xls','NIST TC Data');
[row column]=size(data);
m=['y' 'm' 'c' 'r' 'g' 'b' 'w' 'k'];
i=1;
    for j=1:(column/2)
        x=data(:,i);
        y=data(:,i+1);
        i=i+2;
        plot(x,y,m(j));
        xlabel('temperature');
        ylabel('mV');
        grid on
        hold on
    end