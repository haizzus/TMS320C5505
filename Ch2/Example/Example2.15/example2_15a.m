%
% example2_15a.m - magnitude and phase response of an IIR filter
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals,Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b=[1], a=[1, -1, 0.9]; % Define numerator and denominator coefs
freqz(b,a);            % Plot magnitude and phase responses