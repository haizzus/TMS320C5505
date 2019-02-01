%
% example3_7.m - MATLAB file for designing FIR filter using
%                the Fourier series method
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

omegac = 0.4*pi; % Cutoff frequency
L = 61;		     % Filter order L = 61
M = (L-1)/2;     % M
l = 0:2*M;       % Coefficient index l
h = omegac/pi*sinc(omegac*(l-M)/pi);  % Compute coefficients
omega = -pi:2*pi/200:pi;     % Frequency range
Hd = freqz(h,1,omega);       % Frequency response 
plot((omega/pi),abs(Hd)),... % Use normalized frequency
    xlabel('Normalized frequency'), ylabel('Magnitude'), grid;
axis([-1 1 0 1.2]);