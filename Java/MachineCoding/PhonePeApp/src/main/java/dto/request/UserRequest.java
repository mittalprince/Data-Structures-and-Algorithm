package dto.request;

import dto.UserCategory;
import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class UserRequest {

    private String name;
    private String contactNumber;
    private UserCategory userCategory;
    private String department;

}
