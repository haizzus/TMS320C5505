%
% example2_29.m - MATLAB script for example 2.29
% This example generate random number sample using quantizer

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

N=16; n=[0:N-1];
xn = sqrt(3)*(rand(1,N)-0.5); % Generate zero-mean white noise
q15 = quantizer('fixed', 'convergent', 'wrap', [16 15]); %Q15
Q15int = num2int(q15,xn)
plot(n,Q15int);
axis([0 N-1 -inf inf]);
title('White noise in Q15 integer format');
xlabel('Time index, n'); ylabel('Amplitude');
save xnQ15.dat Q15int -ascii;
