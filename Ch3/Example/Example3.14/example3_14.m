%
% example3_14.m - Adapted from MATLAB Help menu for following tasks:
%   1. Generate the fixed-point random noise as filter input
%   2. Design an FIR filter using least-square method
%   3. Quantize to obtain 16-bit filters
%   4. Perform fixed-point filtering
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

rand('state',0); % Initializing the random number generator
q = quantizer([16,15],'RoundMode','round'); 
xq = randquant(q,256,1); % 256 samples in the range [-1,1)
xin = fi(xq,true,16,15);

b = firls(80,[0 0.11 0.19 1],[1 1 0 0],[1 100]); % Design FIR filter
hd = dfilt.dffir(b); % Create the direct-form FIR filter.
set(hd,'Arithmetic','fixed');  % Quantize filter using 16-bit

y = filter(hd,xin);  % Fixed-point filtering
plot(y);