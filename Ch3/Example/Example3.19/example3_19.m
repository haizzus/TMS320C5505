%
% example3_19.m - Decimate wn48kHz.dat from 48 kHz to 8 kHz
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
load wn48kHz.dat -ascii;           % Load the data from file
fftL = 16384*4;
binsmh = 128;

f=48000*(0:(fftL/2-1))/fftL;       % Frequency scale for display
y=fft(wn48kHz,fftL);               % FFT of the specified block
py=20*log10(abs(y)/fftL);          % Magnitude spectrum
for i = 1:(fftL/2);                % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));grid;title('(a) Original singal spectrum');
xlabel('Frequency (Hz)');ylabel('Magnitude (dB)');
axis([0 24000 10 40]);

fftL = fftL/4; 
len= size(wn48kHz);
x = wn48kHz(1:6:len);              % Decimate to 8 kHz
h=figure;
f=8000*(0:(fftL/2-1))/fftL;        % Frequency scale for display
y=fft(x,fftL);                     % FFT of the specified block
py=20*log10(3*abs(y)/(2*fftL));    % Magnitude spectrum
for i = 1:(fftL/2);                % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));
grid;title('(b) Decimation by 6 without lowpass filter');
xlabel('Frequency (Hz)');ylabel('Magnitude (dB)');
axis([0 4000 10 40]);

xx = decimate(wn48kHz,6,100,'fir'); % Decimate to 8 kHz
h=figure;
f=8000*(0:(fftL/2-1))/fftL;         % Frequency scale for display
y=fft(xx,fftL);                     % FFT of the specified block
py=20*log10(3*abs(y)/(2*fftL));     % Magnitude spectrum
for i = 1:(fftL/2);                 % Smooth diplay
psy(i) = sum(py(i:(i+binsmh)))/binsmh;
end
plot(f,psy(1:(fftL/2)));
grid;title('(c) Decimation by 6 with lowpass filter');
xlabel('Frequency (Hz)'); ylabel('Magnitude (dB)');
axis([0 4000 10 40]);
