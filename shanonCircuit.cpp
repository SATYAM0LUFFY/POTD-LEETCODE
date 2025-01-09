#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class ShannonCircuits {
private:
    static int getValue(const std::string& var, 
                        std::map<std::string, std::vector<int>>& outputs, 
                        std::map<std::string, std::vector<int>>& values, 
                        int cycle) {
        if (values.count(var)) {
            return values[var][cycle];
        }
        return outputs[var][cycle];
    }

    static int computeGate(const std::string& operation, int value1, int value2) {
        if (operation == "AND") {
            return value1 & value2;
        } else if (operation == "OR") {
            return value1 | value2;
        } else if (operation == "NAND") {
            return ~(value1 & value2) & 1;
        } else if (operation == "NOR") {
            return ~(value1 | value2) & 1;
        } else if (operation == "XOR") {
            return value1 ^ value2;
        }
        return 0;
    }

    static void simulateCircuit() {
        // Input number of gates
        int n;
        std::cin >> n;
        std::cin.ignore(); // Clear newline

        // Store gates and their definitions
        std::map<std::string, std::vector<std::string>> gates;
        for (int i = 0; i < n; ++i) {
            std::string line;
            std::getline(std::cin, line);
            
            // Split line into gate name and definition
            size_t pos = line.find('=');
            std::string gateName = line.substr(0, pos);
            std::string gateDefinition = line.substr(pos + 1);
            
            // Remove spaces and parentheses
            gateDefinition.erase(
                std::remove_if(gateDefinition.begin(), gateDefinition.end(), 
                               [](char c) { return c == '(' || c == ')' || c == ' '; }),
                gateDefinition.end()
            );
            
            // Split definition
            std::vector<std::string> definitionParts;
            std::stringstream ss(gateDefinition);
            std::string part;
            while (std::getline(ss, part, ',')) {
                definitionParts.push_back(part);
            }
            
            gates[gateName] = definitionParts;
        }

        // Input time cycles
        int t;
        std::cin >> t;
        
        // Store input values
        std::map<std::string, std::vector<int>> values;
        
        // Read input values
        std::string line;
        std::cin.ignore(); // Clear newline
        while (std::getline(std::cin, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string inputVar;
            iss >> inputVar;
            
            std::vector<int> timings;
            int timing;
            while (iss >> timing) {
                timings.push_back(timing);
            }
            
            values[inputVar] = timings;
        }

        // Simulate circuit outputs
        std::map<std::string, std::vector<int>> outputs;
        for (const auto& gate_pair : gates) {
            outputs[gate_pair.first] = std::vector<int>(t, 0);
        }

        // Compute gate values for each cycle
        for (int cycle = 1; cycle < t; ++cycle) {
            for (const auto& gate_pair : gates) {
                std::string gate = gate_pair.first;
                std::vector<std::string> definition = gate_pair.second;

                std::string operation = definition[0];
                std::string input1 = definition[1];
                std::string input2 = definition[2];

                int value1 = getValue(input1, outputs, values, cycle - 1);
                int value2 = getValue(input2, outputs, values, cycle - 1);

                int result = computeGate(operation, value1, value2);
                outputs[gate][cycle] = result;
            }
        }

        // Output target gate values
        std::string targetGate;
        std::cin >> targetGate;
        
        const auto& targetOutput = outputs[targetGate];
        for (int i = 0; i < t; ++i) {
            std::cout << targetOutput[i] << (i == t-1 ? "\n" : " ");
        }
    }

public:
    static void solve() {
        simulateCircuit();
    }
};

int main() {
    ShannonCircuits::solve();
    return 0;
}