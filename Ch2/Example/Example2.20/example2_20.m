%
% example2_20.m - Generate a signal consists of sinewave 
%                 corrupted by white noise with SNR = 0 dB
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

N=256; A=sqrt(2); w0=0.2*pi;   % Define parameters
n = [0:N-1];                   % Time index
sn = A*sin(w0*n);              % Sine sequence
sd = 12357;                    % Define seed value
rng(sd);                       % Use defined seed
vn = (rand(1,N)-0.5)*sqrt(12); % Zero-mean, unit-variance white noise
xn = sn+vn;                    % Sinewave embedded in white noise
save xn.dat xn -ascii ;
