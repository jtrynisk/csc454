#include <exception>
#include <string>

class SimulationException : virtual public std::exception {

protected:

    int error_number;
    int error_offset;
    std::string error_message;

public:

    explicit
    SimulationException(const std::string& msg, int err_num, int err_off):
        error_number(err_num),
        error_offset(err_off),
        error_message(msg)
        {}

    virtual ~SimulationException() throw () {}

    virtual const char* what() const throw () {
       return error_message.c_str();
    }

    virtual int getErrorNumber() const throw() {
        return error_number;
    }

    virtual int getErrorOffset() const throw() {
        return error_offset;
    }

};
