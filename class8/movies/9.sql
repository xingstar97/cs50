SELECT name
FROM people, movies, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND year == 2004
group by people.id


-- select name from people
-- where id in (
-- SELECT distinct people.id
-- FROM people, movies, stars
-- WHERE movies.id = stars.movie_id
-- AND people.id = stars.person_id
-- AND year == 2004
-- )