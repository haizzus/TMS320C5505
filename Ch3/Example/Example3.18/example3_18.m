%
% example3_18.m - Interpolate wn8kHz.dat from 8 kHz to 48 kHz
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
load wn8kHz.dat -ascii;               % Load the data file
fftL = 4*16384;
binsmh=128;

f=8000*(0:(fftL/2-1))/fftL;           % Frequency scale for display
y=fft(wn8kHz,fftL);                   % FFT of the specified block
py=20*log10(abs(y)/fftL);             % Magnitude
for i = 1:(fftL/2);                   % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));
grid;
xlabel('Frequency (Hz)'); ylabel('Magnitude (dB)');
axis([0 24000 -10 40]);

x = zeros(size(1:fftL));
x(1:6:fftL)= wn8kHz(1024:1:(1023+10923));% Decimate to 8 kHz
h=figure;
f=48000*(0:(fftL/2-1))/fftL;             % Frequency scale for display
y=fft(x,fftL);                           % FFT of the specified block
py=20*log10(2*abs(y)/fftL);              % Magnitude
for i = 1:(fftL/2);                      % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));
grid;
xlabel('Frequency (Hz)'); ylabel('Magnitude (dB)');
axis([0 24000 -10 40]);

% Lowpass filtering
b = fir1(480,1/6);	                  % Design FIR filter in b
xx = conv(x,b);                       % Decimate to 8 kHz
h=figure;
f=48000*(0:(fftL/2-1))/fftL;          % Frequency scale for display
y=fft(xx,fftL);                       % FFT of the specified block
py=20*log10(2*abs(y)/fftL);           % Magnitude
for i = 1:(fftL/2);                   % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));
grid;
xlabel('Frequency (Hz)'); ylabel('Magnitude (dB)');
axis([0 24000 -10 40]);
