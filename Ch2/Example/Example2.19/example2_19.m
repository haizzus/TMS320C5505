%
% example2_19.m Zero-mean, unit variance white noise generator
%   This example generate 256 white noise samples,
%   plot it and save in whiteNoise.dat file

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

N=256;
n=[0:255];
xn = 2*sqrt(3)*(rand(1,N)-0.5);
plot(n, xn);
axis([0 255 -2 2]);
xlabel('Time index, n'); 
ylabel('Amplitude');
save whiteNoise.dat xn -ascii;