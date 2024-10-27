package service;

import dto.request.UserRequest;

public interface UserService {

    String registerNewUser(UserRequest userRequest);

    String findUserIdByContactNumber(String contactNumber);
}
