clear
clc

% Take largest and smallest possible values for each variable
inputArray(1,1) = input('Input largest variable 1: ');
inputArray(1,2) = input('Input smallest variable 1: ');
inputArray(2,1) = input('Input largest variable 2: ');
inputArray(2,2) = input('Input smallest variable 2: ');
inputArray(3,1) = input('Input largest variable 3: ');
inputArray(3,2) = input('Input smallest variable 3: ');
inputArray(4,1) = input('Input largest variable 4: ');
inputArray(4,2) = input('Input smallest variable 4: ');
inputArray(5,1) = input('Input largest variable 5: ');
inputArray(5,2) = input('Input smallest variable 5: ');
inputArray(6,1) = input('Input largest variable 6: ');
inputArray(6,2) = input('Input smallest variable 6: ');
inputArray(7,1) = input('Input largest variable 7: ');
inputArray(7,2) = input('Input smallest variable 7: ');
inputArray(8,1) = input('Input largest variable 8: ');
inputArray(8,2) = input('Input smallest variable 8: ');
inputArray(9,1) = input('Input largest variable 9: ');
inputArray(9,2) = input('Input smallest variable 9: ');
inputArray(10,1) = input('Input largest variable 10: ');
inputArray(10,2) = input('Input smallest variable 10: ');
inputArray(11,1) = input('Input largest variable 11: ');
inputArray(11,2) = input('Input smallest variable 11: ');

% Manually set up first column of cotter array where all 
% variables are at their lowest value
cotterArray(1,1) = inputArray(1,2);
cotterArray(2,1) = inputArray(2,2);
cotterArray(3,1) = inputArray(3,2);
cotterArray(4,1) = inputArray(4,2);
cotterArray(5,1) = inputArray(5,2);
cotterArray(6,1) = inputArray(6,2);
cotterArray(7,1) = inputArray(7,2);
cotterArray(8,1) = inputArray(8,2);
cotterArray(9,1) = inputArray(9,2);
cotterArray(10,1) = inputArray(10,2);
cotterArray(11,1) = inputArray(11,2);

% Fill in all columns from 2 thru 12 with low values
for k = 2:12
    for j = 1:11
        cotterArray(j,k) = inputArray(j,2);
    end
end

% Descend insert the high value at the appropriate row in columns 2 thru 12
j = 1;
for k = 2:12
    cotterArray(j,k) = inputArray(j,1);
    j = j + 1;
end

% Make all values in columns 13 thru 24 the high value
for k = 13:24
    for j = 1:11
        cotterArray(j,k) = inputArray(j,1);
    end
end

% Insert low values at appropriate rows in columns 13 thru 23
j = 1;
for k = 13:23
    cotterArray(j,k) = inputArray(j,2);
    j = j + 1;
end

cotterArray;
 % Run each column through price equation. Enter values into a new single
 % row array
j = 0;
for j = 1:24
    yArray(j) = inputCostsFunction(cotterArray(1,j), cotterArray(2,j), cotterArray(3,j), cotterArray(4,j), cotterArray(5,j), cotterArray(6,j), cotterArray(7,j), cotterArray(8,j), cotterArray(9,j), cotterArray(10,j), cotterArray(11,j));
end

yArray;

% Uses yArray to calculate C-odd values for each variable
j = 0;
for j = 1:11
    coddArray(j) = ((yArray(24) - yArray(j + 11 + 1)) + (yArray(j + 1) - yArray(1))) / 4;
end

coddArray;

% Uses yArray to calculate C-even values for each variable
j = 0;
for j = 1:11
    cevenArray(j) = ((yArray(24) - yArray(j + 11 + 1)) - (yArray(j + 1) - yArray(1))) / 4;
end

cevenArray;

% Creates an array of M values for each variable
j = 0;
for j = 1:11
    mArray(j) = abs(coddArray(j)) + abs(cevenArray(j));
end

mArray;

% Creates an array of S values for each variable
j = 0;
for j = 1:11
    sArray(j) = mArray(j) / sum(mArray);
end

sArray;

