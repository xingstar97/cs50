SELECT name FROM movies, people, stars
WHERE movies.id in
(SELECT movies.id FROM movies, people, stars
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND name = "Kevin Bacon"
AND birth = 1958)
AND movies.id = stars.movie_id
AND people.id = stars.person_id
AND name != "Kevin Bacon"
GROUP BY people.id