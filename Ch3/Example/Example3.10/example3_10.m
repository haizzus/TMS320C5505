%
%  example3_10.m - Design of bandpass filter using Remez algorithm
% 

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

f = [0  0.3  0.4  0.6  0.7  1];  % Frequency range
m = [0  0  1  1  0  0];          % Desired magnitude response
b = remez(17, f, m);             % Remez FIR filter design
[h, omega] = freqz(b, 1, 512);   % Frequency response
plot(f, m, omega/pi, abs(h));
xlabel('Normalized frequency'); ylabel('Magnitude'), grid;