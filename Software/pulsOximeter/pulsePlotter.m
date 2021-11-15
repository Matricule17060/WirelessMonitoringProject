% Import datas

fid10= fopen('tanker.txt');
C10 = textscan(fid10, '%f %f', 'delimiter', ',');
fclose(fid10);

fid11 = fopen('tanker11.txt');
C11 = textscan(fid11, '%f %f', 'delimiter', ',');
fclose(fid11);

fid12 = fopen('tanker12.txt');
C12 = textscan(fid12, '%f %f', 'delimiter', ',');
fclose(fid12);

fid13 = fopen('tanker13.txt');
C13 = textscan(fid13, '%f %f', 'delimiter', ',');
fclose(fid13);



% Statistics 
pulse10 = C10{1,1};
pulse_avg10 = mean(pulse10(pulse10 > 40));

oxymetry10 = C10{1,2};
oxymetry_avg10 = mean(oxymetry10(oxymetry10 ~= 0));


pulse11 = C11{1,1};
pulse_avg11 = mean(pulse11(pulse11 > 40));

oxymetry11 = C11{1,2};
oxymetry_avg11 = mean(oxymetry11(oxymetry11 ~= 0));


pulse12 = C12{1,1};
pulse_avg12 = mean(pulse12(pulse12 > 40));

oxymetry12 = C12{1,2};
oxymetry_avg12 = mean(oxymetry12(oxymetry12 ~= 0));


pulse13 = C13{1,1};
pulse_avg13 = mean(pulse13(pulse13 > 40));

oxymetry13 = C13{1,2};
oxymetry_avg13 = mean(oxymetry13(oxymetry13 ~= 0));



pulse = pulse13;
pulse_avg = pulse_avg13;

% oxymetry = oxymetry11;
% oxymetry_avg = oxymetry_avg11;


N = length(pulse);

t = linspace(1,N,N);

figure(1), plot(t,pulse,'k'),
hold on,
title("Pulsation Cardiaque en fonction du temps"),
xlabel('Temps [sec]'), ylabel('Pulsation [bpm]')
plot([t(1) , t(end)],[pulse_avg , pulse_avg] , 'k--');


% figure(2), plot(t,oxymetry),
% grid on , grid minor, hold on,
% title("Taux d'oxygène sanguin en fonction du temps"),
% xlabel('Temps [sec]'), ylabel("Taux d'oxygène [%]")
% plot([t(1) , t(end)],[oxymetry_avg, oxymetry_avg],'--');