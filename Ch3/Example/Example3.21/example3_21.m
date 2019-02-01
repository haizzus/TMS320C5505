%
% example3_21.m - Decimate timit_4.asc from 16 kHz to 2 kHz, and
%                 interpolate timit_4.asc to 48 kHz
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

load timit_4.asc -ascii;    % Load speech file
soundsc(timit_4, 16000)     % Play at 16 kHz
disp('Press a key to continue ...');
pause;
timit2 = decimate(timit_4,8,60,'fir'); % decimate by 8
soundsc(timit2, 2000)       % Play the decimated speech
disp('Press a key to continue ...');
pause;
timit48 = interp(timit_4,3);% Interpolate to 48 kHz
soundsc(timit48,48000);     % Play the interpolate speech
disp('Press a key to continue ...');
pause;
disp('Example completed');
