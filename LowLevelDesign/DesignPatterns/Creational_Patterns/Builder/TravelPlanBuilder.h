class TravelPlanBuilder
{
private:
    // private constructor so that the object can not be created directly
    TravelPlan m_travelPlan;
    vector<string> hotelBookings;
    TravelPlanBuilder() {}

public:
    //
    void setHotelBookings()
    {
        // make backend API call getHotelBookings('UserId')

    }
    void setLocations()
    {
        // make backend API call getLocations('UserId')

    }
    void setFlightDetails()
    {
        // make backend API call getFlightDetails('UserId')

    }
    void setTrainDetails()
    {
        // make backend API call getTrainDetails(`UserId`)
    }
    void setBusDetails()
    {
        // make backend API call getBusDetails(`UserId`)
    }
};