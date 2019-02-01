%
% example3_8.m - Ploting magnitude responses of rectangular
%                windows
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

M = 8;                     % M = 8 (First window)
L = 2*M+1;                 % Window length
wn = [ones(1,L)];          % Fectangular window
omega = -pi:2*pi/200:pi;   % Frequency range
Hd = freqz(wn,1,omega);    % Frequency response
mag = 20*log10(abs(Hd));   % Log scale

M1 = 20;                   % M = 20 (Second window)
L1 = 2*M1+1;               % Window length
wn1 = [ones(1,L1)];        % Rectangular window
omega = -pi:2*pi/200:pi;   % Frequency range
Hd1 = freqz(wn1,1,omega);  % Frequency response
mag1 = 20*log10(abs(Hd1)); % Log scale

subplot(2,1,1), plot((omega/pi),mag), ...
    xlabel('Normalized frequency'), ylabel('Magnitude(dB)'), grid;
axis([-1 1 -40 40]);
subplot(2,1,2), plot((omega/pi),mag1), ...
    xlabel('Normalized frequency'), ylabel('Magnitude(dB)'), grid;
axis([-1 1 -40 40]);