#train models using libsvm
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-polynomial-fold01-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/16_20-trPCA_01-new.txt 16_20-radialbasis-fold01-G100C1000.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-polynomial-fold02-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/16_20-trPCA_02-new.txt 16_20-radialbasis-fold02-G100C1000.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-polynomial-fold03-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/16_20-trPCA_03-new.txt 16_20-radialbasis-fold03-G100C1000.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-polynomial-fold01-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/48_60-trPCA_01-new.txt 48_60-radialbasis-fold01-G100C1000.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-polynomial-fold02-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/48_60-trPCA_02-new.txt 48_60-radialbasis-fold02-G100C1000.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D1C1.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D2C1.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D3C1.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D1C10.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D2C10.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D3C10.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D1C100.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D2C100.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D3C100.model
./svm-train -t 1 -g 1 -r 0 -d 1 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D1C1000.model
./svm-train -t 1 -g 1 -r 0 -d 2 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D2C1000.model
./svm-train -t 1 -g 1 -r 0 -d 3 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-polynomial-fold03-D3C1000.model
./svm-train -t 2 -g 0.5 -r 0 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G1C1.model
./svm-train -t 2 -g 0.005 -r 0 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G10C1.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G100C1.model
./svm-train -t 2 -g 0.5 -r 0 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G1C10.model
./svm-train -t 2 -g 0.005 -r 0 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G10C10.model
./svm-train -t 2 -g 0.00005 -r 0 -c 10 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G100C10.model
./svm-train -t 2 -g 0.5 -r 0 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G1C100.model
./svm-train -t 2 -g 0.005 -r 0 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G10C100.model
./svm-train -t 2 -g 0.00005 -r 0 -c 100 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G100C100.model
./svm-train -t 2 -g 0.5 -r 0 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G1C1000.model
./svm-train -t 2 -g 0.005 -r 0 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G10C1000.model
./svm-train -t 2 -g 0.00005 -r 0 -c 1000 genderdata/48_60-trPCA_03-new.txt 48_60-radialbasis-fold03-G100C1000.model

#start classifying using libsvm SVMs
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D1C1.model 16_20-polynomial-fold01-D1C1.output &> 16_20-polynomial-fold01-D1C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D2C1.model 16_20-polynomial-fold01-D2C1.output &> 16_20-polynomial-fold01-D2C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D3C1.model 16_20-polynomial-fold01-D3C1.output &> 16_20-polynomial-fold01-D3C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D1C10.model 16_20-polynomial-fold01-D1C10.output &> 16_20-polynomial-fold01-D1C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D2C10.model 16_20-polynomial-fold01-D2C10.output &> 16_20-polynomial-fold01-D2C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D3C10.model 16_20-polynomial-fold01-D3C10.output &> 16_20-polynomial-fold01-D3C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D1C100.model 16_20-polynomial-fold01-D1C100.output &> 16_20-polynomial-fold01-D1C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D2C100.model 16_20-polynomial-fold01-D2C100.output &> 16_20-polynomial-fold01-D2C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D3C100.model 16_20-polynomial-fold01-D3C100.output &> 16_20-polynomial-fold01-D3C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D1C1000.model 16_20-polynomial-fold01-D1C1000.output &> 16_20-polynomial-fold01-D1C1000.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D2C1000.model 16_20-polynomial-fold01-D2C1000.output &> 16_20-polynomial-fold01-D2C1000.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-polynomial-fold01-D3C1000.model 16_20-polynomial-fold01-D3C1000.output &> 16_20-polynomial-fold01-D3C1000.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G1C1.model 16_20-radialbasis-fold01-G1C1.output &> 16_20-radialbasis-fold01-G1C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G10C1.model 16_20-radialbasis-fold01-G10C1.output &> 16_20-radialbasis-fold01-G10C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G100C1.model 16_20-radialbasis-fold01-G100C1.output &> 16_20-radialbasis-fold01-G100C1.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G1C10.model 16_20-radialbasis-fold01-G1C10.output &> 16_20-radialbasis-fold01-G1C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G10C10.model 16_20-radialbasis-fold01-G10C10.output &> 16_20-radialbasis-fold01-G10C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G100C10.model 16_20-radialbasis-fold01-G100C10.output &> 16_20-radialbasis-fold01-G100C10.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G1C100.model 16_20-radialbasis-fold01-G1C100.output &> 16_20-radialbasis-fold01-G1C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G10C100.model 16_20-radialbasis-fold01-G10C100.output &> 16_20-radialbasis-fold01-G10C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G100C100.model 16_20-radialbasis-fold01-G100C100.output &> 16_20-radialbasis-fold01-G100C100.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G1C1000.model 16_20-radialbasis-fold01-G1C1000.output &> 16_20-radialbasis-fold01-G1C1000.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G10C1000.model 16_20-radialbasis-fold01-G10C1000.output &> 16_20-radialbasis-fold01-G10C1000.output
./svm-predict genderdata/16_20-tsPCA_01-new.txt 16_20-radialbasis-fold01-G100C1000.model 16_20-radialbasis-fold01-G100C1000.output &> 16_20-radialbasis-fold01-G100C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D1C1.model 16_20-polynomial-fold02-D1C1.output &> 16_20-polynomial-fold02-D1C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D2C1.model 16_20-polynomial-fold02-D2C1.output &> 16_20-polynomial-fold02-D2C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D3C1.model 16_20-polynomial-fold02-D3C1.output &> 16_20-polynomial-fold02-D3C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D1C10.model 16_20-polynomial-fold02-D1C10.output &> 16_20-polynomial-fold02-D1C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D2C10.model 16_20-polynomial-fold02-D2C10.output &> 16_20-polynomial-fold02-D2C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D3C10.model 16_20-polynomial-fold02-D3C10.output &> 16_20-polynomial-fold02-D3C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D1C100.model 16_20-polynomial-fold02-D1C100.output &> 16_20-polynomial-fold02-D1C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D2C100.model 16_20-polynomial-fold02-D2C100.output &> 16_20-polynomial-fold02-D2C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D3C100.model 16_20-polynomial-fold02-D3C100.output &> 16_20-polynomial-fold02-D3C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D1C1000.model 16_20-polynomial-fold02-D1C1000.output &> 16_20-polynomial-fold02-D1C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D2C1000.model 16_20-polynomial-fold02-D2C1000.output &> 16_20-polynomial-fold02-D2C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-polynomial-fold02-D3C1000.model 16_20-polynomial-fold02-D3C1000.output &> 16_20-polynomial-fold02-D3C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G1C1.model 16_20-radialbasis-fold02-G1C1.output &> 16_20-radialbasis-fold02-G1C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G10C1.model 16_20-radialbasis-fold02-G10C1.output &> 16_20-radialbasis-fold02-G10C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G100C1.model 16_20-radialbasis-fold02-G100C1.output &> 16_20-radialbasis-fold02-G100C1.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G1C10.model 16_20-radialbasis-fold02-G1C10.output &> 16_20-radialbasis-fold02-G1C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G10C10.model 16_20-radialbasis-fold02-G10C10.output &> 16_20-radialbasis-fold02-G10C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G100C10.model 16_20-radialbasis-fold02-G100C10.output &> 16_20-radialbasis-fold02-G100C10.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G1C100.model 16_20-radialbasis-fold02-G1C100.output &> 16_20-radialbasis-fold02-G1C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G10C100.model 16_20-radialbasis-fold02-G10C100.output &> 16_20-radialbasis-fold02-G10C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G100C100.model 16_20-radialbasis-fold02-G100C100.output &> 16_20-radialbasis-fold02-G100C100.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G1C1000.model 16_20-radialbasis-fold02-G1C1000.output &> 16_20-radialbasis-fold02-G1C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G10C1000.model 16_20-radialbasis-fold02-G10C1000.output &> 16_20-radialbasis-fold02-G10C1000.output
./svm-predict genderdata/16_20-tsPCA_02-new.txt 16_20-radialbasis-fold02-G100C1000.model 16_20-radialbasis-fold02-G100C1000.output &> 16_20-radialbasis-fold02-G100C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D1C1.model 16_20-polynomial-fold03-D1C1.output &> 16_20-polynomial-fold03-D1C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D2C1.model 16_20-polynomial-fold03-D2C1.output &> 16_20-polynomial-fold03-D2C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D3C1.model 16_20-polynomial-fold03-D3C1.output &> 16_20-polynomial-fold03-D3C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D1C10.model 16_20-polynomial-fold03-D1C10.output &> 16_20-polynomial-fold03-D1C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D2C10.model 16_20-polynomial-fold03-D2C10.output &> 16_20-polynomial-fold03-D2C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D3C10.model 16_20-polynomial-fold03-D3C10.output &> 16_20-polynomial-fold03-D3C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D1C100.model 16_20-polynomial-fold03-D1C100.output &> 16_20-polynomial-fold03-D1C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D2C100.model 16_20-polynomial-fold03-D2C100.output &> 16_20-polynomial-fold03-D2C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D3C100.model 16_20-polynomial-fold03-D3C100.output &> 16_20-polynomial-fold03-D3C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D1C1000.model 16_20-polynomial-fold03-D1C1000.output &> 16_20-polynomial-fold03-D1C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D2C1000.model 16_20-polynomial-fold03-D2C1000.output &> 16_20-polynomial-fold03-D2C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-polynomial-fold03-D3C1000.model 16_20-polynomial-fold03-D3C1000.output &> 16_20-polynomial-fold03-D3C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G1C1.model 16_20-radialbasis-fold03-G1C1.output &> 16_20-radialbasis-fold03-G1C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G10C1.model 16_20-radialbasis-fold03-G10C1.output &> 16_20-radialbasis-fold03-G10C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G100C1.model 16_20-radialbasis-fold03-G100C1.output &> 16_20-radialbasis-fold03-G100C1.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G1C10.model 16_20-radialbasis-fold03-G1C10.output &> 16_20-radialbasis-fold03-G1C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G10C10.model 16_20-radialbasis-fold03-G10C10.output &> 16_20-radialbasis-fold03-G10C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G100C10.model 16_20-radialbasis-fold03-G100C10.output &> 16_20-radialbasis-fold03-G100C10.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G1C100.model 16_20-radialbasis-fold03-G1C100.output &> 16_20-radialbasis-fold03-G1C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G10C100.model 16_20-radialbasis-fold03-G10C100.output &> 16_20-radialbasis-fold03-G10C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G100C100.model 16_20-radialbasis-fold03-G100C100.output &> 16_20-radialbasis-fold03-G100C100.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G1C1000.model 16_20-radialbasis-fold03-G1C1000.output &> 16_20-radialbasis-fold03-G1C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G10C1000.model 16_20-radialbasis-fold03-G10C1000.output &> 16_20-radialbasis-fold03-G10C1000.output
./svm-predict genderdata/16_20-tsPCA_03-new.txt 16_20-radialbasis-fold03-G100C1000.model 16_20-radialbasis-fold03-G100C1000.output &> 16_20-radialbasis-fold03-G100C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D1C1.model 48_60-polynomial-fold01-D1C1.output &> 48_60-polynomial-fold01-D1C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D2C1.model 48_60-polynomial-fold01-D2C1.output &> 48_60-polynomial-fold01-D2C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D3C1.model 48_60-polynomial-fold01-D3C1.output &> 48_60-polynomial-fold01-D3C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D1C10.model 48_60-polynomial-fold01-D1C10.output &> 48_60-polynomial-fold01-D1C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D2C10.model 48_60-polynomial-fold01-D2C10.output &> 48_60-polynomial-fold01-D2C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D3C10.model 48_60-polynomial-fold01-D3C10.output &> 48_60-polynomial-fold01-D3C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D1C100.model 48_60-polynomial-fold01-D1C100.output &> 48_60-polynomial-fold01-D1C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D2C100.model 48_60-polynomial-fold01-D2C100.output &> 48_60-polynomial-fold01-D2C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D3C100.model 48_60-polynomial-fold01-D3C100.output &> 48_60-polynomial-fold01-D3C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D1C1000.model 48_60-polynomial-fold01-D1C1000.output &> 48_60-polynomial-fold01-D1C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D2C1000.model 48_60-polynomial-fold01-D2C1000.output &> 48_60-polynomial-fold01-D2C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-polynomial-fold01-D3C1000.model 48_60-polynomial-fold01-D3C1000.output &> 48_60-polynomial-fold01-D3C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G1C1.model 48_60-radialbasis-fold01-G1C1.output &> 48_60-radialbasis-fold01-G1C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G10C1.model 48_60-radialbasis-fold01-G10C1.output &> 48_60-radialbasis-fold01-G10C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G100C1.model 48_60-radialbasis-fold01-G100C1.output &> 48_60-radialbasis-fold01-G100C1.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G1C10.model 48_60-radialbasis-fold01-G1C10.output &> 48_60-radialbasis-fold01-G1C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G10C10.model 48_60-radialbasis-fold01-G10C10.output &> 48_60-radialbasis-fold01-G10C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G100C10.model 48_60-radialbasis-fold01-G100C10.output &> 48_60-radialbasis-fold01-G100C10.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G1C100.model 48_60-radialbasis-fold01-G1C100.output &> 48_60-radialbasis-fold01-G1C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G10C100.model 48_60-radialbasis-fold01-G10C100.output &> 48_60-radialbasis-fold01-G10C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G100C100.model 48_60-radialbasis-fold01-G100C100.output &> 48_60-radialbasis-fold01-G100C100.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G1C1000.model 48_60-radialbasis-fold01-G1C1000.output &> 48_60-radialbasis-fold01-G1C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G10C1000.model 48_60-radialbasis-fold01-G10C1000.output &> 48_60-radialbasis-fold01-G10C1000.output
./svm-predict genderdata/48_60-tsPCA_01-new.txt 48_60-radialbasis-fold01-G100C1000.model 48_60-radialbasis-fold01-G100C1000.output &> 48_60-radialbasis-fold01-G100C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D1C1.model 48_60-polynomial-fold02-D1C1.output &> 48_60-polynomial-fold02-D1C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D2C1.model 48_60-polynomial-fold02-D2C1.output &> 48_60-polynomial-fold02-D2C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D3C1.model 48_60-polynomial-fold02-D3C1.output &> 48_60-polynomial-fold02-D3C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D1C10.model 48_60-polynomial-fold02-D1C10.output &> 48_60-polynomial-fold02-D1C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D2C10.model 48_60-polynomial-fold02-D2C10.output &> 48_60-polynomial-fold02-D2C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D3C10.model 48_60-polynomial-fold02-D3C10.output &> 48_60-polynomial-fold02-D3C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D1C100.model 48_60-polynomial-fold02-D1C100.output &> 48_60-polynomial-fold02-D1C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D2C100.model 48_60-polynomial-fold02-D2C100.output &> 48_60-polynomial-fold02-D2C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D3C100.model 48_60-polynomial-fold02-D3C100.output &> 48_60-polynomial-fold02-D3C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D1C1000.model 48_60-polynomial-fold02-D1C1000.output &> 48_60-polynomial-fold02-D1C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D2C1000.model 48_60-polynomial-fold02-D2C1000.output &> 48_60-polynomial-fold02-D2C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-polynomial-fold02-D3C1000.model 48_60-polynomial-fold02-D3C1000.output &> 48_60-polynomial-fold02-D3C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G1C1.model 48_60-radialbasis-fold02-G1C1.output &> 48_60-radialbasis-fold02-G1C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G10C1.model 48_60-radialbasis-fold02-G10C1.output &> 48_60-radialbasis-fold02-G10C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G100C1.model 48_60-radialbasis-fold02-G100C1.output &> 48_60-radialbasis-fold02-G100C1.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G1C10.model 48_60-radialbasis-fold02-G1C10.output &> 48_60-radialbasis-fold02-G1C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G10C10.model 48_60-radialbasis-fold02-G10C10.output &> 48_60-radialbasis-fold02-G10C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G100C10.model 48_60-radialbasis-fold02-G100C10.output &> 48_60-radialbasis-fold02-G100C10.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G1C100.model 48_60-radialbasis-fold02-G1C100.output &> 48_60-radialbasis-fold02-G1C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G10C100.model 48_60-radialbasis-fold02-G10C100.output &> 48_60-radialbasis-fold02-G10C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G100C100.model 48_60-radialbasis-fold02-G100C100.output &> 48_60-radialbasis-fold02-G100C100.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G1C1000.model 48_60-radialbasis-fold02-G1C1000.output &> 48_60-radialbasis-fold02-G1C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G10C1000.model 48_60-radialbasis-fold02-G10C1000.output &> 48_60-radialbasis-fold02-G10C1000.output
./svm-predict genderdata/48_60-tsPCA_02-new.txt 48_60-radialbasis-fold02-G100C1000.model 48_60-radialbasis-fold02-G100C1000.output &> 48_60-radialbasis-fold02-G100C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D1C1.model 48_60-polynomial-fold03-D1C1.output &> 48_60-polynomial-fold03-D1C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D2C1.model 48_60-polynomial-fold03-D2C1.output &> 48_60-polynomial-fold03-D2C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D3C1.model 48_60-polynomial-fold03-D3C1.output &> 48_60-polynomial-fold03-D3C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D1C10.model 48_60-polynomial-fold03-D1C10.output &> 48_60-polynomial-fold03-D1C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D2C10.model 48_60-polynomial-fold03-D2C10.output &> 48_60-polynomial-fold03-D2C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D3C10.model 48_60-polynomial-fold03-D3C10.output &> 48_60-polynomial-fold03-D3C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D1C100.model 48_60-polynomial-fold03-D1C100.output &> 48_60-polynomial-fold03-D1C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D2C100.model 48_60-polynomial-fold03-D2C100.output &> 48_60-polynomial-fold03-D2C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D3C100.model 48_60-polynomial-fold03-D3C100.output &> 48_60-polynomial-fold03-D3C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D1C1000.model 48_60-polynomial-fold03-D1C1000.output &> 48_60-polynomial-fold03-D1C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D2C1000.model 48_60-polynomial-fold03-D2C1000.output &> 48_60-polynomial-fold03-D2C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-polynomial-fold03-D3C1000.model 48_60-polynomial-fold03-D3C1000.output &> 48_60-polynomial-fold03-D3C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G1C1.model 48_60-radialbasis-fold03-G1C1.output &> 48_60-radialbasis-fold03-G1C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G10C1.model 48_60-radialbasis-fold03-G10C1.output &> 48_60-radialbasis-fold03-G10C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G100C1.model 48_60-radialbasis-fold03-G100C1.output &> 48_60-radialbasis-fold03-G100C1.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G1C10.model 48_60-radialbasis-fold03-G1C10.output &> 48_60-radialbasis-fold03-G1C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G10C10.model 48_60-radialbasis-fold03-G10C10.output &> 48_60-radialbasis-fold03-G10C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G100C10.model 48_60-radialbasis-fold03-G100C10.output &> 48_60-radialbasis-fold03-G100C10.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G1C100.model 48_60-radialbasis-fold03-G1C100.output &> 48_60-radialbasis-fold03-G1C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G10C100.model 48_60-radialbasis-fold03-G10C100.output &> 48_60-radialbasis-fold03-G10C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G100C100.model 48_60-radialbasis-fold03-G100C100.output &> 48_60-radialbasis-fold03-G100C100.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G1C1000.model 48_60-radialbasis-fold03-G1C1000.output &> 48_60-radialbasis-fold03-G1C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G10C1000.model 48_60-radialbasis-fold03-G10C1000.output &> 48_60-radialbasis-fold03-G10C1000.output
./svm-predict genderdata/48_60-tsPCA_03-new.txt 48_60-radialbasis-fold03-G100C1000.model 48_60-radialbasis-fold03-G100C1000.output &> 48_60-radialbasis-fold03-G100C1000.output

#write first line of output files to compiled results
head -1 *.output &> libsvm-results.txt