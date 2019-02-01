%
% Example 3.20.m - Convert 44.1 kHz sinewave to 48 kHz sampling rate
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

g = gcd(48000, 44100);              % Greatest common divisor, g = 300
U = 44100/g;                        % Upsampling factor, U=147
D = 48000/g;                        % Downsampling factor, D = 160

N = 24*D;
b = fir1(N,1/D,kaiser(N+1,7.8562)); % Design FIR filter in b
b = U*b;                            % Passband gain = U
Fs = 48000;                         % Original sampling frequency: 48kHz
n = 0:10239;                        % 10240 samples, 0.213 seconds long
x = sin(2*pi*1000/Fs*n);            % Original signal, sinusoid at 1 kHz
y = upfirdn(x,b,U,D);               % 9408 samples, still 0.213 seconds

% Overlay original (48 kHz) with resampled signal (44.1 kHz) in red
stem(n(1:49)/Fs,x(1:49)); 
hold on
stem(n(1:45)/(Fs*U/D),y(13:57),'r','filled');
xlabel('Time (seconds)');
ylabel('Signal value');
