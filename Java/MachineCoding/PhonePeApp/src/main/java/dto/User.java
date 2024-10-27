package dto;

import lombok.Builder;
import lombok.Data;

@Builder
@Data
public class User {

    private String id;
    private String name;
    private String contactNumber;
    private UserCategory userCategory;
    private String department;

}
