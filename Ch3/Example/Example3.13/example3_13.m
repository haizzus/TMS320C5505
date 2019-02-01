%
% example3_13 - Ggenerate the sinewave at 1500 Hz
%               corrupted by white noise
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

Fs = 8000;      % Sampling rate
Ts = 1/Fs;      % Total samples
F = 1500;       % Sinewave frequency
sinewave = sin(2*pi*F*(0:Ts:1));              % Generate sinewave
noise = sqrt(0.1).*randn(1,length(0:Ts:1));   % var = 0.1
xn = sinewave+noise;             % Combine sinewave with noise
in = xn(1:256);                  % Using first 256 samples only
xn_int = round(32768*in./max(abs(in))); % Normalize to 16-bit integer
plot(xn_int); axis([1 256 -32768 32767]);
ylabel('Amplitude'); xlabel('Sample index, n');
fid = fopen('xn_int.dat','w');   % Save signal to xn_int.dat
fprintf(fid,'%4.0f\n',xn_int);   % Save in integer format
fclose(fid);
