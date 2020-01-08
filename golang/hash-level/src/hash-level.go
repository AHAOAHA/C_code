/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: hash-level.go
 * Author: ahaoozhang
 * Date: 2019-08-06 16:43:24 (星期二)
 * Describe: 
 *************************************************/
package hash-level

import (
	"errors"
)

type HASH_LENGTH uint32
type HASH_LEVEL uint32

var _hash_level_map = []hash_level_node
var _hash_level_mod = []uint32

type hash_level_node struct {
	_key uint32
	_value interface{}
	_used bool
}

//
func is_prime_num(num uint32) bool {
	for begin := 2; begin < num; begin++ {
		if num % begin == 0 {
			return false
		}
	}
	return true
}

//返回当前的hash map的阶数
func get_level_primes() ([]uint32, error) {
	var Primes []uint32
	hash_level_num := HASH_LEVEL
	
	for hash_level_len := HASH_LENGTH; hash_level_len >= 0; hash_level_len-- {
		if is_prime_num(hash_level_len) {
			Primes = append(Primes, hash_level_len)
			if len(Primes) >= HASH_LEVEL {
				return Primes, nil
			}
		}
	}
	return nil, errors.New("Primes not enough")
}

func init_hash_level() bool {
	//确定阶数
	Primes, err := get_level_primes()
	if err != nil {
		return false
	}
}

func NewHashLevelMap(len uint32, level uint32) *hash_level_map {
	if len <= 0 || level <= 0 {
		return nil
	}

	HASH_LEVEL = level
	HASH_LENGTH = len

	if !ok  == init_hash_level() {
		return nil
	}

	return &_hash_level_map
}

func GetValue(key uint32)(interface{} ,bool) {
	var hashVal uint32
	var i int

	//找合适位置
	for i := 0; i < HASH_LEVEL; i++ {
		hashVal = key % _hash_level_mod[i]
		if _hash_level_map[HASH_LENGTH * i + hashVal]._key == key {
			break
		}
	}

	if i == HASH_LEVEL {
		return nil, false
	}

	return _hash_level_map[HASH_LEVEL * i + hashVal], true
}

func PutValue(key uint32, value interface{}) bool {
	var hashVal uint32
	var i int

	//找合适位置
	for i = 0; i < HASH_LEVEL; i++ {
		hashVal = key % _hash_level_mod[i]
		if _hash_level_map[HASH_LENGTH * i + hashVal]._used == false {
			break
		}
	}

	if i == HASH_LEVEL {
		return false
	}

	//插入数据
	_hash_level_map[HASH_LENGTH * i + hashVal]._value = value
	_hash_level_map[HASH_LENGTH * i + hashVal]._key = key
	_hash_level_map[HASH_LENGTH * i + hashVal]._used = true
}
