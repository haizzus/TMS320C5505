%
% example2_26.m - Evaluate 16-bit and 8-bit speech
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

load timit1.asc;                 % Speech sampled at 8 kHz, 16 bits
plot(timit1); 
title('16-bit speech');
xlabel('Time index, n'); 
ylabel('Amplitude');
soundsc(timit1, 8000, 16);		% Play 16-bit speech
disp ('Press any key to continue');
pause;
qx = round(timit1/256);         % Resampled to 8 bits
plot(qx); title('8-bit speech');
xlabel('Time index, n'); 
ylabel('Amplitude');
soundsc(qx, 8000, 16);			% Play 8-bit speech