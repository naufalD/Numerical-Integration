#include "include/quasirandom.h"

#include <functional>

double trapezoidIntegration(int numberTraps, double start, double end, std::function<double(double)> theFunction){
    double interval = (end-start)/numberTraps;

    if (numberTraps==1){
        return (interval/2)*(theFunction(start)+theFunction(end));
    }
    else{
        double result {0};
        for (int i {0}; i<numberTraps; ++i){
            result = result + (interval/2)*(theFunction(start+i*interval)+theFunction(start+(i+1)*interval));
        }
        return result;
    }
}

double simpsonsIntegration(int numberPars, double start, double end, std::function<double(double)> theFunction){
    double interval = (end-start) / numberPars;

    if (numberPars==1){
        return (interval/3)*theFunction(start) + (4*interval/3)*theFunction(start+interval/2) + (interval/3)*theFunction(end);
    }
    else{
        double result {0};
        for (int i {0}; i<numberPars; ++i){
            result = result + (interval/3)*theFunction(start+i*interval) + (4*interval/3)*theFunction(start+i*interval+interval/2) + (interval/3)*theFunction(start+(i+1)*interval);
        }
        return 0.5*result;
    }
}

double monteCarloIntegration(int numberPoints, double start, double end, std::function<double(double)> theFunction){
    double sum {0};
    double randomPoint {0};
    for (int i{0}; i<numberPoints; ++i){
        randomPoint = arc4random() / pow(2,32) * (end-start);
        randomPoint = randomPoint+start;
        sum = sum + theFunction(randomPoint);
    }
    return (end-start)/numberPoints*sum;
}

double monacoIntegration(int division, double start, double end, std::function<double(double)> theFunction){
    int numPoints {1};
    double sum {theFunction(start)};
    double current {start};
    double randomPoint {0};
    while (current<end){
        randomPoint = arc4random() / pow(2,32) * ((end-start)/static_cast<double>(division));
        current = current+randomPoint;
        if (current>end){
            sum = sum + theFunction(end);
        }
        else{
            sum = sum+theFunction(current);
        }
        numPoints = numPoints+1;
    }
    return (end-start)*sum/numPoints;
}

double sobolIntegration(int division, double start, double end, sobolDimension Rng, std::function<double(double)> theFunction){
    int numPoints {1};
    double sum {theFunction(start)};
    double current {start};
    double randomPoint {0};


    while (current<end){
        randomPoint = Rng.getPoint() * ((end-start)/static_cast<double>(division));
        Rng.nextPoint();
        current = current+randomPoint;
        if (current>end){
            sum = sum + theFunction(end);
        }
        else{
            sum = sum+theFunction(current);
        }
        numPoints = numPoints+1;
    }
    return (end-start)*sum/numPoints;
}
