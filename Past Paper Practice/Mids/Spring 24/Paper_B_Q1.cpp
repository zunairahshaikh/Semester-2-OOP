#include <iostream>
#include <cmath>
using namespace std;

class StatisticalAnalyzer{
    public:
        static double computeAverage(const double data[], int size){
            double sum = 0.0;

            if(size == 0){
                cout << "Array empty" << endl;
                return 0.0;
            }
            else{
                for(int i = 0; i < size; i++){
                    sum += data[i];
                }
            }

            return sum/size;
        }

        static double claculateStandardDeviation(const double data[], int size){
            double sumOfSquare = 0.0;
            double mean = StatisticalAnalyzer::computeAverage(data, size);

            for(int i = 0; i < size; i++){
                sumOfSquare += pow(data[i] - mean, 2);
            }

            return sqrt(sumOfSquare/(size-1));
        }
};

int main(){
    double dataSet[] = {2.4, 3.6, 9.8, 7.0};
    int size = sizeof(dataSet)/sizeof(dataSet[0]);

    double avg = StatisticalAnalyzer::computeAverage(dataSet, size);
    double standev = StatisticalAnalyzer::claculateStandardDeviation(dataSet, size);

    cout << avg << endl;
    cout << standev << endl;
}
