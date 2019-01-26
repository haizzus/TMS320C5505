%
%  exercise1_4.m - MATLAB Script for playing a speech file at different rate
%
%  For the book "Real Time Digital Signal Processing:
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

load timit_1.asc;
x=timit_1/32768;
disp('Sampling rate 8000 Hz');
sound(x,8000);
disp(' hit return to continue');
pause;
disp('Sampling rate 12000 Hz');
sound(x,12000);
disp(' hit return to continue');
pause;
disp('Sampling rate 16000 Hz');
sound(x,16000);
disp(' hit return to continue');
pause;
disp('Sampling rate 24000 Hz');
sound(x,24000);
disp(' hit return to continue');
pause;
disp('Sampling rate 32000 Hz');
sound(x,32000);
disp(' done');