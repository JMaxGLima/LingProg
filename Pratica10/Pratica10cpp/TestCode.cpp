#include <iostream>
#include <exception>
using namespace std;

class MedicalError : public exception {}; // Inherit from std::exception
class DiagnosticError : public MedicalError {}; // Inherit from MedicalError
class SurgeryError : public MedicalError {}; // Inherit from MedicalError

int main() {
    try {
        throw SurgeryError(); // Need to instantiate the object
    } catch (MedicalError &e) {
        // Handle any medical error
        cerr << "Generic medical error" << endl;
    } catch (DiagnosticError &e) {
        // Handle diagnostic error only
        cerr << "Diagnostic error" << endl;
    } catch (SurgeryError &e) {
        // Handle surgery error only
        cerr << "Surgery error" << endl;
    }

    return 0;
}
