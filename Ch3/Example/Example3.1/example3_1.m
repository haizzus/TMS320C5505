%
% example3_1.m - Magnitue, phase, and group delay responses
%                of 2-point moving-average filter

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b=[0.5, 0.5]; a = [1];  % Define filter coefficients
freqz(b,a);             % Show magnitude and phase response
figure;
grpdelay(b,a);          % Show group delay