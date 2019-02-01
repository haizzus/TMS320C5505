%
% example2_15b.m - magnitude and phase response of an IIR filter
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals,Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b=[1, 0, 0, 0, 0, 0, 0, 0, -1]; % Numerator
a=[1, -1];                      % Denominator
freqz(b,a);                     % Plot frequency response