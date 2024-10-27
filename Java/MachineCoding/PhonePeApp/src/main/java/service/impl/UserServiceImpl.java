package service.impl;

import dto.User;
import dto.request.UserRequest;
import org.apache.commons.lang3.StringUtils;
import service.UserService;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.UUID;

public class UserServiceImpl implements UserService {

    public Map<String, String> contactNumberToUserIdMapping = new HashMap<>();
    public Map<String, User> userIdToDtoMapping = new HashMap<>();

    @Override
    public String registerNewUser(UserRequest userRequest) {

        if (Objects.isNull(userRequest)) {
            return StringUtils.EMPTY;
        }

        if (StringUtils.isNotBlank(userRequest.getContactNumber()) &&
            !contactNumberToUserIdMapping.containsKey(userRequest.getContactNumber())) {

            User user = User
                    .builder()
                    .id(UUID.randomUUID().toString())
                    .contactNumber(userRequest.getContactNumber())
                    .name(userRequest.getName())
                    .department(userRequest.getDepartment())
                    .userCategory(userRequest.getUserCategory())
                    .build();

            contactNumberToUserIdMapping.put(user.getContactNumber(), user.getId());
            userIdToDtoMapping.put(user.getContactNumber(), user);
            return user.getId();
        }
        return StringUtils.EMPTY;
    }

    @Override
    public String findUserIdByContactNumber(String contactNumber) {
        return contactNumberToUserIdMapping.get(contactNumber);
    }
}
