close all;
pos=fopen('position.txt');
vel=fopen('velocity.txt');
m=fopen('mass.txt');
x=str2num(fgetl(pos))';
y=str2num(fgetl(pos))';
z=str2num(fgetl(pos))';

vx=str2num(fgetl(vel))';
vy=str2num(fgetl(vel))';
vz=str2num(fgetl(vel))';
v=sqrt(vx.^2+vy.^2+vz.^2);

mass=str2num(fgetl(m))';

fclose(pos);
fclose(vel);
fclose(m);

figure;
plot(x,y);
grid on;
xlabel('X/m');
ylabel('Y/m');

figure;
plot(v);
grid on;
ylabel('vy/m');

