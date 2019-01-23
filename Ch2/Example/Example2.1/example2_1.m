%
% Example 2.1 Sinewave generator
% This example generate 32 sine sample,
% plot it and save in sine.dat file

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

n = [0:31];             % Time index n
omega = 0.25*pi;        % Digital frequency
xn = 2*sin(omega*n);    % Sinewave generation
plot(n, xn, '-o');      % Samples are marked by 'o'
xlabel('Time index, n'); 
ylabel('Amplitude');
axis([0 31 -2 2]);		% Define ranges of plot
save sine.dat xn -ascii;% Save in ASCII data file