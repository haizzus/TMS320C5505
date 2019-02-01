%
% hamWindow.m - Hamming window function and its magnitude response
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

L = 41; n = 0:40;             % Window length
wn = hamming(L);              % Generate window coefficients
omega = -pi:2*pi/200:pi;      % Ffrequency range
Hd = freqz(wn,1,omega);       % Frequency response
mag = 20*log10(abs(Hd));      % in dB scale
subplot(2,1,1), plot(n,wn), ...
ylabel('Amplitude'); axis([0 (L-1) 0 1]);
subplot(2,1,2), plot((omega/pi),mag), ...
    xlabel('Normalized frequency'), ylabel('Magnitude(dB)'), grid;
axis([-1 1 -80 40]);
