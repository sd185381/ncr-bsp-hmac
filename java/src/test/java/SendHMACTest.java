import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class SendHMACTest {

	@Test
	@DisplayName("GET Request")
	public void testSendGet() {
		Integer status;
		try {
			System.out.println(Sytem.getenv("SECRET_KEY"));
			status = SendGet.callGet(System.getenv("SECRET_KEY"), System.getenv("SHARED_KEY"),
					System.getenv("ORGANIZATIOn"));
		} catch (Exception e) {
			e.printStackTrace();
			status = 500;
		}
		assertEquals(200, status);
	}

	@Test
	@DisplayName("POST Request")
	public void testSendPost() {
		Integer status;
		try {
			System.out.println(Sytem.getenv("SHARED_KEY"));
			status = SendGet.callGet(System.getenv("SECRET_KEY"), System.getenv("SHARED_KEY"),
					System.getenv("ORGANIZATIOn"));
		} catch (Exception e) {
			e.printStackTrace();
			status = 500;
		}
		assertEquals(200, status);
	}
}