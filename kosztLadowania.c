#include <stdio.h>

int main(void)
{
	int session_count;
	double price_per_kwh;
	double total_cost = 0.0;

	printf("Podaj liczbe sesji ladowania: ");
	if (scanf("%d", &session_count) != 1 || session_count <= 0) {
		fprintf(stderr, "Liczba sesji musi byc dodatnia.\n");
		return 1;
	}

	printf("Podaj cene za 1 kWh (PLN): ");
	if (scanf("%lf", &price_per_kwh) != 1 || price_per_kwh < 0.0) {
		fprintf(stderr, "Cena musi byc liczba nieujemna.\n");
		return 1;
	}

	for (int session = 1; session <= session_count; session++) {
		double duration_hours;
		double charging_power_kw;
		double energy_kwh;
		double session_cost;

		printf("Sesja %d - podaj czas ladowania (godziny): ", session);
		if (scanf("%lf", &duration_hours) != 1 || duration_hours <= 0.0) {
			fprintf(stderr, "Czas ladowania musi byc dodatni.\n");
			return 1;
		}

		printf("Sesja %d - podaj moc ladowarki (kW): ", session);
		if (scanf("%lf", &charging_power_kw) != 1 || charging_power_kw <= 0.0) {
			fprintf(stderr, "Moc ladowarki musi byc dodatnia.\n");
			return 1;
		}

		energy_kwh = duration_hours * charging_power_kw;
		session_cost = energy_kwh * price_per_kwh;
		total_cost += session_cost;

		printf("Sesja %d: %.2f kWh, koszt %.2f PLN\n",
			   session, energy_kwh, session_cost);
	}

	printf("Laczny koszt: %.2f PLN\n", total_cost);
	return 0;
}
