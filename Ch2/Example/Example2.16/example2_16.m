%
% example2_16.m - Compute and plot amplitude spectrum of sinewave
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

N=100; f = 1000; fs = 10000; % Define parameter values
n=[0:N-1]; k=[0:N-1];        % Define time and frequency indices
omega=2*pi*f/fs;             % Frequency of sinewave
xn=sin(omega*n);             % Generate sinewave
Xk=fft(xn,N);                % Perform DFT
magXk=20*log10(abs(Xk));     % Compute magnitude spectrum
plot(k, magXk); axis([0, N/2, -inf, inf]); % plot from 0 to pi
xlabel('Frequency index, k');
ylabel('Magnitude (dB)');
