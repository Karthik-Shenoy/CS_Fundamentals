class TravelBudgetBuilder
{
private:
    // private constructor so that the object can not be created directly
    TravelPlan m_travelPlan;
    TravelPlanBuilder() {}

public:
    //
    void setHotelBookingsBudget()
    {
        // make backend API call getHotelBookings('UserId')

    }
    void setFlightBudget()
    {
        // make backend API call getFlightDetails('UserId')

    }
    void setTrainBudget()
    {
        // make backend API call getTrainDetails(`UserId`)
    }
    void setBusBudget()
    {
        // make backend API call getBusDetails(`UserId`)
    }
};