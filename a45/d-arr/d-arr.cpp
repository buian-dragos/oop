//#include "d-arr.h"
//
//DynamicVector::DynamicVector()
//{
//    events = new Event[20];
//    capacity = 20;
//    number_of_events = 0;
//}
//
//void DynamicVector::resize()
//{
//    int i;
//    int new_size = capacity * 2;
//    Event* new_arr = new Event[new_size];
//
//    memcpy(new_arr, events, capacity * sizeof(Event));
//
//    capacity = new_size;
//    delete[] events;
//    events = new_arr;
//}
//
//void DynamicVector::add(Event new_event)
//{
//    if (number_of_events == capacity)
//        resize();
//    events[number_of_events] = new_event;
//    number_of_events++;
//}
//
//void DynamicVector::remove(int index)
//{
//    for (int i = index; i < number_of_events; i++) {
//        events[i] = events[i + 1];
//    }
//    number_of_events--;
//}
//
//
//
//int DynamicVector::length()
//{
//    return number_of_events;
//}
//
//void DynamicVector::update(Event new_event, int index)
//{
//    events[index] = new_event;
//}
//
//int DynamicVector::index(std::string name, std::string date)
//{
//    for (int i = 0; i < number_of_events; i++) {
//        if ((name.compare(events[i].get_name()) == 0) && (date.compare(events[i].get_date()) == 0))
//            return i;
//    }
//    return -1;
//}
//
//std::string DynamicVector::list()
//{
//    std::string rs;
//    for (int i = 0; i < number_of_events; i++) {
//        rs.append(events[i].get_name());
//        rs.append(" ");
//        rs.append(events[i].get_desc());
//        rs.append(" ");
//        rs.append(events[i].get_date());
//        rs.append(" ");
//        rs.append(events[i].no_str());
//        rs.append(" ");
//        rs.append(events[i].get_link());
//        rs.append("\n");
//    }
//    return rs;
//}
//
//
//
