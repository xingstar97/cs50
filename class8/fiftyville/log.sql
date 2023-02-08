-- Keep a log of any SQL queries you execute as you solve the mystery.

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = "Humphrey Street"


SELECT name, transcript FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28

-- Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <=25

SELECT caller
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <60

SELECT passport_number FROM passengers
WHERE flight_id in
(SELECT id FROM flights WHERE
year = 2021
AND month = 7
AND day = 29
AND origin_airport_id in
(SELECT id 
FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1)

SELECT name, phone_number, passport_number, license_plate
FROM people, bank_accounts
WHERE account_number in
(SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street")
AND bank_accounts.person_id = people.id
AND license_plate in
(SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <=25)
AND phone_number in
(SELECT caller
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <60)
AND passport_number in
(SELECT passport_number FROM passengers
WHERE flight_id in
(SELECT id FROM flights WHERE
year = 2021
AND month = 7
AND day = 29
AND origin_airport_id in
(SELECT id 
FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1))

-- Bruce|(367) 555-5533|5773159633|94KL13X

SELECT city FROM airports
WHERE id in 
(SELECT destination_airport_id FROM flights, passengers
WHERE flights.id = passengers.flight_id
AND passport_number = "5773159633"
AND year = 2021
AND month = 7
AND day = 29
)

-- New York City

SELECT name FROM people 
WHERE phone_number in 
(SELECT receiver FROM phone_calls
WHERE caller = "(367) 555-5533"
AND year = 2021
AND month = 7
AND day = 28
AND duration <60)

-- Robin