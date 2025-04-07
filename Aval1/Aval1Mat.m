clear all
clc
disp('Operations on a number:')
num = input('Type a number: ');
factorial_val=1;
for i=1:1:num
    factorial_val = factorial_val*i;
end
square_root = sqrt(num);
power = num.^2;
fprintf('The factorial of the number is: %.2f\n', factorial_val);
fprintf('The square root of the number is: %.2f\n', square_root);
fprintf('The number raised to the power of 2 is: %.2f\n', power);
