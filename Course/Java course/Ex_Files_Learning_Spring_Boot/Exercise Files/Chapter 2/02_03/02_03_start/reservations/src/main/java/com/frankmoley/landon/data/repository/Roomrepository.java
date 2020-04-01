package com.frankmoley.landon.data.repository;

import com.frankmoley.landon.data.entity.Room;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;
@Repository
public interface Roomrepository extends CrudRepository<Room, Long> {
    Room findBynumber(String number);
}
