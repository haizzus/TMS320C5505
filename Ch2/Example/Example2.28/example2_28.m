%
% example2_28.m - MATLAB script for example 2.28
% This example generate random number sample using quantizer

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

N=16; 
n=[0:N-1];
xn = sqrt(3)*(rand(1,N)-0.5); % Generate zero-mean white noise
q15 = quantizer('fixed', 'convergent', 'wrap', [16 15]); %Q15
q3 = quantizer('fixed', 'convergent', 'wrap', [4 3]);    %Q3
y15 = quantize(q15,xn);       % Quantization using Q15 format
y3 = quantize(q3,xn);         % Quantization using Q3 format
en = y15-y3,                  % Differences between Q15 and Q3
plot(n,y15,'-o',n,y3,'-x',n,en);
axis([0 N-1 -inf inf]);
title('Quantized samples, Q15 marked o, Q3 marked x');
xlabel('Time index, n'); 
ylabel('Amplitude');
