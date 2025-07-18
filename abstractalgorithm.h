#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

template <class In, class Out>
class AbstractAlgorithm {
public:
    AbstractAlgorithm() : mInput() {}
    AbstractAlgorithm(const In& input) : mInput (input) {}
    virtual ~AbstractAlgorithm(){}
    virtual int run () = 0;
    void setInput (const In& input) {
        mInput = input;
    }
    In& getInput () {
        return mInput;
    }
    Out& getOutput () {
        return mOutput;
    }
protected:
    In mInput;
    Out mOutput;
};

#endif // ABSTRACTALGORITHM_H
