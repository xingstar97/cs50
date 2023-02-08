SELECT title FROM movies, people, stars
where title in (SELECT title FROM movies, people, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND name = "Johnny Depp")
AND movies.id = stars.movie_id
AND people.id = stars.person_id
AND name = "Helena Bonham Carter"




-- SELECT title FROM movies
-- JOIN stars s1 ON movies.id = s1.movie_id
-- JOIN people as p1 ON p1.id = s1.person_id
-- join stars s2 on movies.id = s2.movie_id
-- JOIN people as p2 ON p2.id = s2.person_id
-- WHERE p1.name = "Johnny Depp"
-- and p2.name = "Helena Bonham Carter";