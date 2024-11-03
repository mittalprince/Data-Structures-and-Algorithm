import com.example.parkinglotSystem.factory.VehicleFactory;
import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;
import com.example.parkinglotSystem.services.ParkingService;
import com.example.parkinglotSystem.strategy.FirstAvailableStrategy;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class ParkingLotTest {
    private ParkingService service;

    @BeforeEach
    public void setUp() {
        ParkingLot parkingLot = ParkingLot.getInstance("PR1234", 2, 6, new FirstAvailableStrategy());
        service = new ParkingService(parkingLot);
    }

    @Test
    public void testParkVehicle() throws Exception {
        Ticket ticket = service.parkVehicle(VehicleType.CAR, "KA-01-1234", "Black");
        assertNotNull(ticket);
    }

    @Test
    public void testUnparkVehicle() throws Exception {
        Ticket ticket = service.parkVehicle(VehicleType.CAR, "KA-01-1234", "Black");
        service.unParkVehicle(ticket);
    }
}