--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

DROP DATABASE universe;
--
-- Name: universe; Type: DATABASE; Schema: -; Owner: freecodecamp
--

CREATE DATABASE universe WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'C.UTF-8' LC_CTYPE = 'C.UTF-8';


ALTER DATABASE universe OWNER TO freecodecamp;

\connect universe

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: comet; Type: TABLE; Schema: public; Owner: freecodecamp
--

CREATE TABLE public.comet (
    comet_id integer NOT NULL,
    name character varying(30) NOT NULL,
    star_id integer,
    age_in_millions_of_years integer
);


ALTER TABLE public.comet OWNER TO freecodecamp;

--
-- Name: comet_comet_id_seq; Type: SEQUENCE; Schema: public; Owner: freecodecamp
--

CREATE SEQUENCE public.comet_comet_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.comet_comet_id_seq OWNER TO freecodecamp;

--
-- Name: comet_comet_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: freecodecamp
--

ALTER SEQUENCE public.comet_comet_id_seq OWNED BY public.comet.comet_id;


--
-- Name: galaxy; Type: TABLE; Schema: public; Owner: freecodecamp
--

CREATE TABLE public.galaxy (
    galaxy_id integer NOT NULL,
    name character varying(30) NOT NULL,
    galaxy_type character varying(30) NOT NULL,
    age_in_millions_of_years integer NOT NULL,
    width_in_au integer NOT NULL
);


ALTER TABLE public.galaxy OWNER TO freecodecamp;

--
-- Name: galaxy_galaxy_id_seq; Type: SEQUENCE; Schema: public; Owner: freecodecamp
--

CREATE SEQUENCE public.galaxy_galaxy_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.galaxy_galaxy_id_seq OWNER TO freecodecamp;

--
-- Name: galaxy_galaxy_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: freecodecamp
--

ALTER SEQUENCE public.galaxy_galaxy_id_seq OWNED BY public.galaxy.galaxy_id;


--
-- Name: moon; Type: TABLE; Schema: public; Owner: freecodecamp
--

CREATE TABLE public.moon (
    moon_id integer NOT NULL,
    name character varying(30) NOT NULL,
    distance_from_earth_au numeric(10,5) NOT NULL,
    mass_in_earth_masses numeric(10,5) NOT NULL,
    description text,
    has_life boolean NOT NULL,
    age_in_millions_of_years integer NOT NULL,
    planet_id integer
);


ALTER TABLE public.moon OWNER TO freecodecamp;

--
-- Name: moon_moon_id_seq; Type: SEQUENCE; Schema: public; Owner: freecodecamp
--

CREATE SEQUENCE public.moon_moon_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.moon_moon_id_seq OWNER TO freecodecamp;

--
-- Name: moon_moon_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: freecodecamp
--

ALTER SEQUENCE public.moon_moon_id_seq OWNED BY public.moon.moon_id;


--
-- Name: planet; Type: TABLE; Schema: public; Owner: freecodecamp
--

CREATE TABLE public.planet (
    planet_id integer NOT NULL,
    name character varying(30) NOT NULL,
    distance_from_earth_au numeric(10,5) NOT NULL,
    mass_in_earth_masses numeric(10,5) NOT NULL,
    description text,
    has_life boolean NOT NULL,
    age_in_millions_of_years integer NOT NULL,
    star_id integer,
    is_gas_giant boolean NOT NULL
);


ALTER TABLE public.planet OWNER TO freecodecamp;

--
-- Name: planet_planet_id_seq; Type: SEQUENCE; Schema: public; Owner: freecodecamp
--

CREATE SEQUENCE public.planet_planet_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.planet_planet_id_seq OWNER TO freecodecamp;

--
-- Name: planet_planet_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: freecodecamp
--

ALTER SEQUENCE public.planet_planet_id_seq OWNED BY public.planet.planet_id;


--
-- Name: star; Type: TABLE; Schema: public; Owner: freecodecamp
--

CREATE TABLE public.star (
    star_id integer NOT NULL,
    name character varying(30) NOT NULL,
    mass_in_earth_masses numeric(10,5) NOT NULL,
    distance_from_earth_in_au numeric(10,5) NOT NULL,
    galaxy_id integer,
    age_in_millions_of_years integer NOT NULL
);


ALTER TABLE public.star OWNER TO freecodecamp;

--
-- Name: star_star_id_seq; Type: SEQUENCE; Schema: public; Owner: freecodecamp
--

CREATE SEQUENCE public.star_star_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.star_star_id_seq OWNER TO freecodecamp;

--
-- Name: star_star_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: freecodecamp
--

ALTER SEQUENCE public.star_star_id_seq OWNED BY public.star.star_id;


--
-- Name: comet comet_id; Type: DEFAULT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.comet ALTER COLUMN comet_id SET DEFAULT nextval('public.comet_comet_id_seq'::regclass);


--
-- Name: galaxy galaxy_id; Type: DEFAULT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.galaxy ALTER COLUMN galaxy_id SET DEFAULT nextval('public.galaxy_galaxy_id_seq'::regclass);


--
-- Name: moon moon_id; Type: DEFAULT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.moon ALTER COLUMN moon_id SET DEFAULT nextval('public.moon_moon_id_seq'::regclass);


--
-- Name: planet planet_id; Type: DEFAULT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.planet ALTER COLUMN planet_id SET DEFAULT nextval('public.planet_planet_id_seq'::regclass);


--
-- Name: star star_id; Type: DEFAULT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.star ALTER COLUMN star_id SET DEFAULT nextval('public.star_star_id_seq'::regclass);


--
-- Data for Name: comet; Type: TABLE DATA; Schema: public; Owner: freecodecamp
--

INSERT INTO public.comet VALUES (1, 'Icarus', 1, 1200);
INSERT INTO public.comet VALUES (2, 'Lysithea', 2, 850);
INSERT INTO public.comet VALUES (3, 'Perihel', 3, 3100);
INSERT INTO public.comet VALUES (4, 'Astreon', 2, 1900);
INSERT INTO public.comet VALUES (5, 'Velorum', 4, 2600);


--
-- Data for Name: galaxy; Type: TABLE DATA; Schema: public; Owner: freecodecamp
--

INSERT INTO public.galaxy VALUES (1, 'Milky Way', 'Spiral', 13600, 100000);
INSERT INTO public.galaxy VALUES (2, 'Andromeda', 'Spiral', 10000, 220000);
INSERT INTO public.galaxy VALUES (3, 'Sombrero', 'Spiral', 10000, 50000);
INSERT INTO public.galaxy VALUES (4, 'Whirlpool', 'Spiral', 5000, 80000);
INSERT INTO public.galaxy VALUES (5, 'Triangulum', 'Spiral', 3000, 60000);
INSERT INTO public.galaxy VALUES (6, 'Cartwheel', 'Ring', 2000, 150000);


--
-- Data for Name: moon; Type: TABLE DATA; Schema: public; Owner: freecodecamp
--

INSERT INTO public.moon VALUES (1, 'Selene', 0.00257, 0.01230, 'Rocky companion with maria plains', false, 4400, 1);
INSERT INTO public.moon VALUES (2, 'Pharos', 0.03410, 0.00110, 'Bright icy shell with shallow crevasses', false, 2700, 2);
INSERT INTO public.moon VALUES (3, 'Nyx', 0.04850, 0.00072, 'Charcoal-dark surface, retrograde orbit', false, 3100, 2);
INSERT INTO public.moon VALUES (4, 'Tethys Minor', 0.08940, 0.00840, 'Ridge-lined equator and impact basins', false, 4200, 3);
INSERT INTO public.moon VALUES (5, 'Eos', 0.12000, 0.00210, 'Icy crust over suspected brine ocean', false, 3600, 3);
INSERT INTO public.moon VALUES (6, 'Rhya', 0.15100, 0.00460, 'Sulfur jets and patchy frost caps', false, 1900, 3);
INSERT INTO public.moon VALUES (7, 'Canto', 0.21000, 0.00040, 'Shepherd moon shaping faint rings', false, 2500, 4);
INSERT INTO public.moon VALUES (8, 'Marelle', 0.24500, 0.00095, 'Porous rubble pile, elongated shape', false, 1200, 4);
INSERT INTO public.moon VALUES (9, 'Halimede', 0.30000, 0.00380, 'Subsurface ammonia slush hints at activity', false, 3300, 5);
INSERT INTO public.moon VALUES (10, 'Lacrimosa', 0.35500, 0.00125, 'Blue-white ice cliffs, thin exosphere', false, 2100, 5);
INSERT INTO public.moon VALUES (11, 'Vesper', 0.41000, 0.00055, 'Tumbling rotation, chaotic seasons', false, 1500, 5);
INSERT INTO public.moon VALUES (12, 'Oriole', 0.46500, 0.00033, 'Dusty orange hue, frequent meteoroid hits', false, 900, 6);
INSERT INTO public.moon VALUES (13, 'Kite', 0.52000, 0.00029, 'Tiny shepherd stabilizing inner ring arc', false, 800, 6);
INSERT INTO public.moon VALUES (14, 'Tarn', 0.57500, 0.00180, 'Dark hydrocarbon deposits in polar craters', false, 2600, 6);
INSERT INTO public.moon VALUES (15, 'Brim', 0.63000, 0.00260, 'Fresh ice fractures suggest recent tidal stress', false, 1400, 7);
INSERT INTO public.moon VALUES (16, 'Auric', 0.68500, 0.00310, 'Golden albedo from sulfur frost cycles', false, 1800, 7);
INSERT INTO public.moon VALUES (17, 'Cairn', 0.74000, 0.00061, 'Heavily cratered, no detectable volatiles', false, 4100, 8);
INSERT INTO public.moon VALUES (18, 'Sable', 0.79500, 0.00073, 'Carbon-rich surface, retains faint dust tail', false, 3200, 8);
INSERT INTO public.moon VALUES (19, 'Dawnstar', 0.85000, 0.00490, 'Briny plume vents near fractured equator', false, 2200, 9);
INSERT INTO public.moon VALUES (20, 'Iris', 0.90500, 0.00105, 'Shallow subsurface ocean; auroras from flux tube', false, 2400, 9);


--
-- Data for Name: planet; Type: TABLE DATA; Schema: public; Owner: freecodecamp
--

INSERT INTO public.planet VALUES (1, 'Aurelia', 4.32000, 1.12000, 'Temperate terrestrial world with shallow seas', true, 4200, 1, false);
INSERT INTO public.planet VALUES (2, 'Borealis', 12.75000, 0.89000, 'Cold desert planet with thin atmosphere', false, 3100, 1, false);
INSERT INTO public.planet VALUES (3, 'Caldera', 0.72000, 0.65000, 'Volcanically active, high sulfur content', false, 1500, 2, false);
INSERT INTO public.planet VALUES (4, 'Demeris', 18.40000, 2.30000, 'Ocean planet with deep global sea', false, 5200, 2, false);
INSERT INTO public.planet VALUES (5, 'Erebus', 6.15000, 9.80000, 'Massive gas giant with faint rings', false, 6100, 3, true);
INSERT INTO public.planet VALUES (6, 'Fiora', 27.90000, 0.73000, 'Rocky world with pink sodium skies', false, 2700, 3, false);
INSERT INTO public.planet VALUES (7, 'Gaelan', 42.30000, 18.50000, 'Ice giant rich in methane clouds', false, 6800, 3, true);
INSERT INTO public.planet VALUES (8, 'Hadal', 55.60000, 6.40000, 'Warm mini-Neptune with dense haze', false, 4500, 4, true);
INSERT INTO public.planet VALUES (9, 'Ilyra', 2.85000, 1.05000, 'Mild climate, patchy continents and archipelagos', true, 3900, 4, false);
INSERT INTO public.planet VALUES (10, 'Jannis', 9.42000, 0.54000, 'Tidal-locked with a narrow habitable terminator', false, 2000, 2, false);
INSERT INTO public.planet VALUES (11, 'Kryos', 73.80000, 7.90000, 'Distant gas giant with large moon system', false, 7200, 4, true);
INSERT INTO public.planet VALUES (12, 'Lumen', 1.38000, 0.92000, 'Cloudy super-Earth with strong auroras', false, 1800, 1, false);


--
-- Data for Name: star; Type: TABLE DATA; Schema: public; Owner: freecodecamp
--

INSERT INTO public.star VALUES (1, 'Sun', 1000.00000, 100.00000, 1, 5000);
INSERT INTO public.star VALUES (2, 'star1', 2000.00000, 10.00000, 3, 8000);
INSERT INTO public.star VALUES (3, 'star2', 50000.00000, 1000.00000, 6, 1000);
INSERT INTO public.star VALUES (4, 'star3', 50000.00000, 500.00000, 1, 3000);
INSERT INTO public.star VALUES (5, 'star4', 70000.00000, 200.00000, 5, 1000);
INSERT INTO public.star VALUES (6, 'star5', 30000.00000, 50.00000, 1, 4000);


--
-- Name: comet_comet_id_seq; Type: SEQUENCE SET; Schema: public; Owner: freecodecamp
--

SELECT pg_catalog.setval('public.comet_comet_id_seq', 5, true);


--
-- Name: galaxy_galaxy_id_seq; Type: SEQUENCE SET; Schema: public; Owner: freecodecamp
--

SELECT pg_catalog.setval('public.galaxy_galaxy_id_seq', 6, true);


--
-- Name: moon_moon_id_seq; Type: SEQUENCE SET; Schema: public; Owner: freecodecamp
--

SELECT pg_catalog.setval('public.moon_moon_id_seq', 20, true);


--
-- Name: planet_planet_id_seq; Type: SEQUENCE SET; Schema: public; Owner: freecodecamp
--

SELECT pg_catalog.setval('public.planet_planet_id_seq', 12, true);


--
-- Name: star_star_id_seq; Type: SEQUENCE SET; Schema: public; Owner: freecodecamp
--

SELECT pg_catalog.setval('public.star_star_id_seq', 6, true);


--
-- Name: comet comet_name_key; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.comet
    ADD CONSTRAINT comet_name_key UNIQUE (name);


--
-- Name: comet comet_pkey; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.comet
    ADD CONSTRAINT comet_pkey PRIMARY KEY (comet_id);


--
-- Name: galaxy galaxy_name_key; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.galaxy
    ADD CONSTRAINT galaxy_name_key UNIQUE (name);


--
-- Name: galaxy galaxy_pkey; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.galaxy
    ADD CONSTRAINT galaxy_pkey PRIMARY KEY (galaxy_id);


--
-- Name: moon moon_name_key; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.moon
    ADD CONSTRAINT moon_name_key UNIQUE (name);


--
-- Name: moon moon_pkey; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.moon
    ADD CONSTRAINT moon_pkey PRIMARY KEY (moon_id);


--
-- Name: planet planet_name_key; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.planet
    ADD CONSTRAINT planet_name_key UNIQUE (name);


--
-- Name: planet planet_pkey; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.planet
    ADD CONSTRAINT planet_pkey PRIMARY KEY (planet_id);


--
-- Name: star star_name_key; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.star
    ADD CONSTRAINT star_name_key UNIQUE (name);


--
-- Name: star star_pkey; Type: CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.star
    ADD CONSTRAINT star_pkey PRIMARY KEY (star_id);


--
-- Name: comet comet_star_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.comet
    ADD CONSTRAINT comet_star_id_fkey FOREIGN KEY (star_id) REFERENCES public.star(star_id);


--
-- Name: moon moon_planet_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.moon
    ADD CONSTRAINT moon_planet_id_fkey FOREIGN KEY (planet_id) REFERENCES public.planet(planet_id);


--
-- Name: planet planet_star_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.planet
    ADD CONSTRAINT planet_star_id_fkey FOREIGN KEY (star_id) REFERENCES public.star(star_id);


--
-- Name: star star_galaxy_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: freecodecamp
--

ALTER TABLE ONLY public.star
    ADD CONSTRAINT star_galaxy_id_fkey FOREIGN KEY (galaxy_id) REFERENCES public.galaxy(galaxy_id);


--
-- PostgreSQL database dump complete
--

