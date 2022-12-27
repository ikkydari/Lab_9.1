switch (p[i].specialization)
{
case COMPUTER_SCIENCE:
    cout << "| " << setw(9) << setprecision(2) << fixed << right
        << p[i].programmingRate << " |" << setw(13) << right << "|" << endl;
    break;
case IT:
    cout << "| " << setw(9) << setprecision(2) << fixed << right
        << p[i].chMRate << " |" << setw(13) << right << "|" << endl;
    break;
case MATH:
case PHYSICS_AND_IT:
case HANDICRAFT:
    cout << "| " << setw(11) << right << "|"
        << " " << setw(8) << right
        << p[i].pedagogicRate << " |" << endl;
    break;
}
        }
        cout << "========================================================================="
            << endl;
        cout << endl;
}

bool AverageRateCheck(int a, int b, int c)
{
    return ((a + b + c) / 3) > 4.5;
}
string GetMaximumAverageSubject(float arr[])
{
    string subjects[] = { "Фізика", "Математика", "Програмування", "Чисельні методи", "Педагогіка" };
    int max = 0;
    int index = -1;
    int n = 5;
    // Iterate the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            // If current value is greater than max  value then replace it with max value
            max = arr[i];
            index = i;
        }
    }
    return subjects[index];
}
int LineSearch(Student* p, const int N)
{
    int amountOfStudent = 0, // початкова кількість студентів, що отримали  більше 4.5
        physicsRateOveral = 0, mathRateOveral = 0, programmingRateOveral = 0,
        chMRateOveral = 0, pedagogicRateOveral = 0;
    float arr[] = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < N; i++)
    {
        arr[0] += p[i].physicsRate;
        arr[1] += p[i].mathRate;
        ++physicsRateOveral;
        ++mathRateOveral;
        switch (p[i].specialization)
        {
        case COMPUTER_SCIENCE:
            if (AverageRateCheck(p[i].mathRate, p[i].physicsRate, p[i].programmingRate))
            {
                arr[2] += p[i].programmingRate;
                ++amountOfStudent;
                ++programmingRateOveral;
            }
            break;
        case IT:
            if (AverageRateCheck(p[i].mathRate, p[i].physicsRate, p[i].chMRate))
            {
                arr[3] += p[i].chMRate;
                ++amountOfStudent;
                ++chMRateOveral;
            }
            break;
        case MATH:
        case PHYSICS_AND_IT:
        case HANDICRAFT:
            if (AverageRateCheck(p[i].mathRate, p[i].physicsRate, p[i].pedagogicRate))
            {
                arr[4] += p[i].pedagogicRate;
                ++amountOfStudent;
                ++pedagogicRateOveral;
            }
            break;
        }
    }
    arr[0] /= physicsRateOveral;
    arr[1] /= mathRateOveral;
    arr[2] /= programmingRateOveral;
    arr[3] /= chMRateOveral;
    arr[4] /= pedagogicRateOveral;
    const string maxSubject = GetMaximumAverageSubject(arr);
    cout << "Cередній бал якого найбільший з такого предмату як - " << maxSubject << endl;

    return amountOfStudent;
}