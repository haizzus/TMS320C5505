%
% Example 2.11a Mgnitude and phase response of an IIR filter
% This example plots magnitude and phase response of an IIR filter

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b=[1];          % Define numerator
a=[1, -1, 0.9]; % Denominator 
zplane(b,a);    % Pole-zero plot