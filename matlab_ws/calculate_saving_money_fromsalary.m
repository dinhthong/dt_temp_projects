%% Program to calculate the end money you will get if you deposit money to the bank monthly
% Assume that year nenshuu doesn't increase
% Doesn't care about bonunses
% The script maybe not totally correct (reference Mr HHH)
clear all;

rate_hourly = 2500; % rate per hour [Japanese yen]
daily_overtime_inhour = 1.5;
yearly_salary = 400*10000; % [Japanese yen] 400 man

% currency exchange rate
c_rate_yentovnd = 165; % As of 2023.Aug.27
overtime_rate_hourly=rate_hourly*1.2; %% overtime rate per hour [Japanese yen]

% normal minute rate 
bunkyuu = rate_hourly/60;
bunkyuu_vnd = bunkyuu*c_rate_yentovnd;
% work in overtime hourly rate

daily_rate=rate_hourly*8;
work_days=yearly_salary/daily_rate;
leave_days = 365-work_days;

% overtime is 1 hour per day on average
yearly_overtime_salary = work_days*overtime_rate_hourly*daily_overtime_inhour; % [Japanese yen]

actual_yearly_salary = yearly_salary + yearly_overtime_salary;
actual_monthly_salary = actual_yearly_salary/12;

%% calculating all the consumption every month
tax = actual_monthly_salary*0.2;
housing_rent = 55000;
other_expense = 90000; %% foods
utilities_fee_monthly = 6500; %% kou.netsu.hi
gas_fee_monthly = 6000;

saving_salary_per_month = actual_monthly_salary-housing_rent-other_expense-tax;
saving_salary_per_month = saving_salary_per_month - utilities_fee_monthly - gas_fee_monthly;

yearly_interest_rate = 8/100;
% number of year working
year_to_save = 5;
end_month = year_to_save*12-1;
final_sum = 0;

for i = 0:end_month
    current_interest = saving_salary_per_month*(1+yearly_interest_rate)^(i/12)
    final_sum = final_sum+current_interest
end

% nenkin can be received after you completing all the procedure and leave
% Japan for good
nenkin = year_to_save*1.1*yearly_salary/12; % [JP yen]
final_money_vnd = final_sum*c_rate_yentovnd + nenkin*c_rate_yentovnd;
