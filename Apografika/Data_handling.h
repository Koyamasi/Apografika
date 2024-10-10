#pragma once

#include "New_data.h"

namespace Apografika {

    public ref class Data_handling {
    private:
        static Data_handling^ instance;
        System::Collections::Generic::List<New_data^>^ dataList;

        Data_handling() {
            dataList = gcnew System::Collections::Generic::List<New_data^>();
        }

    public:
        static Data_handling^ GetInstance() {
            if (instance == nullptr) {
                instance = gcnew Data_handling();
            }
            return instance;
        }

        void AddData(New_data^ newData) {
            dataList->Add(newData);
        }

        System::Collections::Generic::List<New_data^>^ GetAllData() {
            return dataList;
        }
    };
}
