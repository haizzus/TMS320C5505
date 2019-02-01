%
% example3_12.m - Adapted from MATLAB Help menu for following tasks:
%   1. Design an FIR filter using least-square method
%   2. Quantize and analyze the 16-bit filter with reference filter
%   3. Quantize and compare 12-bit and 16-bit filters
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

b = firls(80,[0 0.11 0.19 1],[1 1 0 0],[1 100]); % Design an FIR filter
hd = dfilt.dffir(b); % Create the direct-form FIR filter.
set(hd,'Arithmetic','fixed');  % Quantize filter using 16-bit
% fvtool(b,hd);      % Compare the fixed-point filter with reference
h1 = copy(hd);       % Copy hd to h1
set(h1,'CoeffWordLength',12); % Use 12 bits for coefficients
fvtool(hd, h1);      % Compare 12-bit & 16-bit filters