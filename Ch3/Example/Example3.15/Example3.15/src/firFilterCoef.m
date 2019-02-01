% 
%  Project: Example 3.15: floating-point implementation of FIR filter - Chapter 4
%  File name: firFilterCoef.m   
%
%  Description: This MATLAB script generates the FIR coefficients
%               and use the filter on a given input data
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

fid = fopen('input.pcm', 'r');
in = fread(fid, 'int16');
f=[0 0.3 0.4 0.5 0.6 1];
m=[0 0 1 1 0 0 ];
b=remez(47, f, m);
[h, omega]=freqz(b,1,512);
plot(f,m,omega/pi, abs(h));

y=filter(b, 1, in/32767.0);
p=spectrum(y, 128);
p2=spectrum(in, 128);

figure(1);
plot(20*log10(abs(p)));
grid;
figure(2);
plot(20*log10(abs(p2)));
grid;
fclose(fid);
