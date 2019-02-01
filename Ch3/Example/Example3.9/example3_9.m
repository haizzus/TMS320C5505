%
% example3_9.m - Designing FIR filter using Hamming window
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

omegac = 0.4*pi; % Cutoff frequency
L = 61;          % Filter order L = 61
M = (L-1)/2;     % M
l = 0:2*M;       % Coefficient index l
h = omegac/pi*sinc(omegac*(l-M)/pi);  % Compute coefficients
wn = 0.54 -0.46*cos(2*pi*l/(L-1));    % Hamming window
hwn = h.*wn;     % Windowing
omega = -pi:2*pi/200:pi;   % Frequency range
Hr = freqz(h,1,omega);     % Frequency response-Rectangular
Hd = freqz(hwn,1,omega);   % Frequency response-Hamming  
plot((omega/pi),abs(Hr),':r',(omega/pi),abs(Hd),'-b');
xlabel('Normalized frequency'), ylabel('Magnitude'), grid;
legend('Rectangular window','Hamming window')
axis([-1 1 0 1.2]);